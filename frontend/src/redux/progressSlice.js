// progressSlice.js
import { createSlice } from '@reduxjs/toolkit';

const initialState = {
  progress: 0,
};

const progressSlice = createSlice({
  name: 'progress',
  initialState,
  reducers: {
    setProgress: (state, action) => {
      state.progress = action.payload + 1;
    },
  },
});

export const { setProgress } = progressSlice.actions;

export default progressSlice.reducer;