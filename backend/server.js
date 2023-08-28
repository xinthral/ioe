const express = require('express');
const dotenv = require('dotenv');
const colors = require('colors');
const cors = require('cors');
const { json } = require('body-parser');
const { nanoid } = require('nanoid');

dotenv.config({ path: './config.env' });

const app = express();

app.use(cors());
app.use(json());

let todos = [];
let players = [];

/* Todo List */
app.get('/todos', (req, res) => res.send(todos));
app.post('/todos', (req, res) => {
	const todo = { id: nanoid(), title: req.body.title, completed: false };
	todos.push(todo);
	return res.send(todo);
});
app.patch('/todos/:id', (req, res) => {
	const id = req.params.id;
	const index = todos.findIndex((todo) => todo.id === id);
	const completed = Boolean(req.body.completed);
	if (index > -1) { todos[index].completed = completed;}
	return res.send(todos[index]);
});
app.delete('/todos/:id', (req, res) => {
	const id = req.params.id;
	const index = todos.findIndex((todo) => todo.id === id);
	if (index > -1) { todos.splice(index, 1); }
	res.send(todos);
});

/* Players */
app.get('/players', (req, res) => res.send(players));
app.post('/players', (req, res) => {
	const player = { id: nanoid(), name: req.body.name, level: 0, completed: false };
	players.push(player);
	return res.send(player);
});
app.patch('/players/:id', (req, res) => {
	const id = req.params.id;
	const index = players.findIndex((player) => player.id === id);
	const completed = Boolean(req.body.completed);
	if (index > -1) { players[index].completed = completed;}
	return res.send(players[index]);
});
app.patch('/players/:id/incrementLevel', (req, res) => {
	const id = req.params.id;
	const index = players.findIndex((player) => player.id === id);
	const level = req.body.level;
	if (index > -1) { players[index].level = level; }
	return res.send(players[index]);
});
// app.patch('/players/:id/decrementLevel', (req, res) => {
// 	const id = req.params.id;
// 	const index = players.findIndex((player) => player.id === id);
// 	const level = req.body.newLevel;
// 	if (index > -1) { players[index].level = level; }
// 	return res.send(players[index]);
// });
app.delete('/players/:id', (req, res) => {
	const id = req.params.id;
	const index = players.findIndex((player) => player.id === id);
	if (index > -1) { players.splice(index, 1);	}
	res.send(players);
});

const PORT = 7000;
app.listen(PORT, console.log(`Server running on port ${PORT}`.green.bold));
