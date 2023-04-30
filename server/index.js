// server/index.js

const express = require("express");

const PORT = process.env.PORT || 3001;
const SERVER = 'http://localhost';

const app = express();

app.get('/api', (req, res) => {
  res.json({ message: 'Hello from server!' });
});

app.listen(PORT, () => {
  console.log(`Server listening on ${SERVER}:${PORT}`);
});