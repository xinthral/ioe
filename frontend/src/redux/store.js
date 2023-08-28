import { configureStore } from '@reduxjs/toolkit';
import todoReducer from './todoSlice';
import progressReducer from './progressSlice';
import playerReducer from './playerSlice';

export default configureStore({
	reducer: {
		todos: todoReducer,
		progress: progressReducer,
		players: playerReducer,
	},
});
