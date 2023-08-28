import { createAsyncThunk, createSlice } from "@reduxjs/toolkit";
import { nanoid } from "nanoid";

export const getPlayersAsync = createAsyncThunk(
	'players/getPlayersAsync',
	async () => {
		const resp = await fetch('http://localhost:7000/players');
		if (resp.ok) {
			const players = await resp.json();
			return { players };
		}
	}
);

export const addPlayerAsync = createAsyncThunk(
	'players/addPlayerAsync',
	async (payload) => {
		const resp = await fetch("http://localhost:7000/players", {
			method: 'POST',
			headers: { 'Content-Type': 'application/json', },
			body: JSON.stringify({ name: payload.name }),
		});
		if (resp.ok) {
			const player = await resp.json();
			return { player };
		}
	}
);

export const completePlayerAsync = createAsyncThunk(
	'players/completePlayerAsync',
	async (payload) => {
		const resp = await fetch(`http://localhost:7000/players/${payload.id}`, {
			method: 'PATCH',
			headers: { 'Content-Type': 'application/json', },
			body: JSON.stringify({ completed: payload.completed }),
		});
		if (resp.ok) {
			const player = await resp.json();
			return { player };
		}
	}
);

export const incrementPlayerLevelAsync = createAsyncThunk(
	'players/incrementPlayerLevelAsync',
	async (payload) => {
		const resp = await fetch(`http://localhost:7000/players/${payload.id}/incrementLevel`, {
			method: 'PATCH',
			headers: { 'Content-Type': 'application/json', },
			body: JSON.stringify({ level: payload.level }),
		});
		if (resp.ok) {
			const player = await resp.json();
			return { player };
		}
	}
);

export const deletePlayerAsync = createAsyncThunk(
	'players/deletePlayerAsync',
	async (payload) => {
		const resp = await fetch(`http://localhost:7000/players/${payload.id}`, {
			method: 'DELETE',
		});
		if (resp.ok) {
			return { id: payload.id };
		}
	}
);

export const playerSlice = createSlice({
    name: 'players',
    initialState: [],
    reducers: {
        addPlayer: (state, action) => {
			const player = {
				id: nanoid(),
				name: action.payload.name,
				level: 0,
				completed: false,
			};
			state.push(player);
		},
		completePlayer: (state, action) => {
			const index = state.findIndex((player) => player.id === action.payload.id);
			state[index].completed = action.payload.completed;
		},
		incrementLevel: (state, action) => {
			const index = state.findIndex((player) => player.id === action.payload.id);
			state[index].level = action.payload.newLevel;
		},
		deletePlayer: (state, action) => {
			return state.filter((player) => player.id !== action.payload.id);
		},
    },
    extraReducers: {
        [getPlayersAsync.fulfilled]: (state, action) => {
			return action.payload.players;
		},
		[addPlayerAsync.fulfilled]: (state, action) => {
			state.push(action.payload.player);
		},
		[completePlayerAsync.fulfilled]: (state, action) => {
			const index = state.findIndex(
				(player) => player.id === action.payload.player.id
			);
			state[index].completed = action.payload.player.completed;
		},
		[incrementPlayerLevelAsync.fulfilled]: (state, action) => {
			const index = state.findIndex(
				(player) => player.id === action.payload.player.id
			);
			state[index].level = action.payload.player.level;
		},
		[deletePlayerAsync.fulfilled]: (state, action) => {
			return state.filter((player) => player.id !== action.payload.id);
		},
    },
});

export const { addPlayer, completePlayer, deletePlayer, incrementLevel } = playerSlice.actions;

export default playerSlice.reducer;