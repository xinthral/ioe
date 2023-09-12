import { createAsyncThunk, createSlice } from "@reduxjs/toolkit";
import { nanoid } from "nanoid";

/* ----- Globals ----- */
let g_headers = { 'Content-Type': 'application/json', }

/* ----- Async Calls ----- */
export const getUsersAsync = createAsyncThunk(
	'users/getUsersAsync',
	async () => {
		const resp = await fetch('http://localhost:7000/users');
		if (resp.ok) {
			const users = await resp.json();
			return { users };
		}
	}
);
	
export const addUserAsync = createAsyncThunk(
	'users/addUserAsync',
	async (payload) => {
		const resp = await fetch("http://localhost:7000/users", {
			method: 'POST',
			headers: g_headers,
			body: JSON.stringify({ name: payload.name }),
		});
		if (resp.ok) {
			const user = await resp.json();
			return { user };
		}
	}
);
	
export const completeUserAsync = createAsyncThunk(
	'users/completeUserAsync',
	async (payload) => {
		const resp = await fetch(`http://localhost:7000/users/${payload.id}`, {
			method: 'PATCH',
			headers: g_headers,
			body: JSON.stringify({ completed: payload.completed }),
		});
		if (resp.ok) {
			const user = await resp.json();
			return { user };
		}
	}
);
		
export const incrementUserLevelAsync = createAsyncThunk(
	'users/incrementUserLevelAsync',
	async (payload) => {
		const resp = await fetch(`http://localhost:7000/users/${payload.id}/incrementLevel`, {
			method: 'PATCH',
			headers: g_headers,
			body: JSON.stringify({ level: payload.level }),
		});
		if (resp.ok) {
			const user = await resp.json();
			return { user };
		}
	}
);
	
export const decrementUserLevelAsync = createAsyncThunk(
	'users/decrementUserLevelAsync',
	async (payload) => {
		const resp = await fetch(`http://localhost:7000/users/${payload.id}/decrementLevel`, {
			method: 'PATCH',
			headers: g_headers,
			body: JSON.stringify({ level: payload.level }),
		});
		if (resp.ok) {
			const user = await resp.json();
			return { user };
		}
	}
);
		
export const deleteUserAsync = createAsyncThunk(
	'users/deleteUserAsync',
	async (payload) => {
		const resp = await fetch(`http://localhost:7000/users/${payload.id}`, {
			method: 'DELETE',
			headers: g_headers,
		});
		if (resp.ok) {
			return { id: payload.id };
		}
	}
);
	
export const userSlice = createSlice({
	name: 'users',
	initialState: [],
	reducers: {
		addUser: (state, action) => {
			const user = {
				id: nanoid(),
				name: action.payload.name,
				level: 0,
				completed: false,
			};
		state.push(user);
		},
		completeUser: (state, action) => {
			const index = state.findIndex((user) => user.id === action.payload.id);
			state[index].completed = action.payload.completed;
		},
		incrementLevel: (state, action) => {
			const index = state.findIndex((user) => user.id === action.payload.id);
			state[index].level = action.payload.newLevel;
		},
		decrementLevel: (state, action) => {
			const index = state.findIndex((user) => user.id === action.payload.id);
			state[index].level = action.payload.newLevel;
		},
		deleteUser: (state, action) => {
			return state.filter((user) => user.id !== action.payload.id);
		},
	},
	extraReducers: (builder) => {
		builder.addCase(getUsersAsync.fulfilled, (state, action) => {
			return action.payload.users;
		})
		builder.addCase(addUserAsync.fulfilled, (state, action) => {
			state.push(action.payload.user);
		})
		builder.addCase(completeUserAsync.fulfilled, (state, action) => {
			const index = state.findIndex(
				(user) => user.id === action.payload.user.id
			);
			state[index].completed = action.payload.user.completed;
		})
		builder.addCase(incrementUserLevelAsync.fulfilled, (state, action) => {
			const index = state.findIndex(
				(user) => user.id === action.payload.user.id
			);
			state[index].level = action.payload.user.level;
		})
		builder.addCase(decrementUserLevelAsync.fulfilled, (state, action) => {
			const index = state.findIndex(
				(user) => user.id === action.payload.user.id
			);
			state[index].level = action.payload.user.level;
		})
		builder.addCase(deleteUserAsync.fulfilled, (state, action) => {
			return state.filter((user) => user.id !== action.payload.id);
		})
	},
});
	
export const { addUser, completeUser, deleteUser, incrementLevel, decrementLevel } = userSlice.actions;

export default userSlice.reducer;