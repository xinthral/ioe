import path from 'path'
import express from 'express'
import connectDB from './config/db.js'
import userRoutes from './routes/userRoutes.js'
import { errorHandler, notFound } from './middleware/errorMiddleware.js'

import dotenv from 'dotenv'
// const colors = require('colors');
import cors from 'cors'
import { json } from 'body-parser'
import { nanoid } from 'nanoid'
import {closePlayerConnection} from './db/integrity/schema/testPlayerTable.js'
import {closeToonConnection} from './db/integrity/schema/testToonTable.js'

app.use(cors());
app.use(json());
// dotenv.config()
dotenv.config({ path: './config.env' });

// connect to database
connectDB()

const app = express()

// Body parser
app.use(express.json())

// API routes
app.use('/api/user', userRoutes)

// deployment configuration
const __dirname = path.resolve()

if (process.env.NODE_ENV === 'production') {
  app.use(express.static(path.join(__dirname, '/frontend/build')))

  app.get('*', (req, res) =>
    res.sendFile(path.resolve(__dirname, 'frontend', 'build', 'index.html'))
  )
}

// Middleware
app.use(notFound)
app.use(errorHandler)

// ASync Routes

/*! Establish Variables */

let todos = [];
let players = [];


process.on('SIGTERM', shutdownConnections);
process.on('SIGINT', shutdownConnections);

function shutdownConnections() {
	console.log('User Requested shutdown...');
	closePlayerConnection();
	closeToonConnection();
    setTimeout(() => {
		console.log('Closed Remaining Connections');
		process.exit(0);
    }, 1000);
};

/*! Todo List API */
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

/*! Players API */
app.get('/players', (req, res) => res.send(players));
app.post('/players', (req, res) => {
	const player = { id: nanoid(), name: req.body.name, level: 0, completed: false };
	players.push(player);
	return res.send(player);
});
app.delete('/players/:id', (req, res) => {
	const id = req.params.id;
	const index = players.findIndex((player) => player.id === id);
	if (index > -1) { players.splice(index, 1);	}
	res.send(players);
});
//! PlayerList Mark Player
app.patch('/players/:id', (req, res) => {
	const id = req.params.id;
	const index = players.findIndex((player) => player.id === id);
	const completed = Boolean(req.body.completed);
	if (index > -1) { players[index].completed = completed;}
	return res.send(players[index]);
});
//! (In)/(De)crementLevel
app.patch('/players/:id/incrementLevel', (req, res) => {
	const id = req.params.id;
	const index = players.findIndex((player) => player.id === id);
	const level = req.body.level;
	if (index > -1) { players[index].level = level + 1; }
	return res.send(players[index]);
});
app.patch('/players/:id/decrementLevel', (req, res) => {
	const id = req.params.id;
	const index = players.findIndex((player) => player.id === id);
	const level = req.body.level;
	if (index > -1) { players[index].level = level - 1; }
	return res.send(players[index]);
});

//! Engine API request
app.get('/engine/loadDatabase', (req, res) => {
	/*! Build Databases in Memory */
	// const dbcontroller = require('./db/controller');
	// dbcontroller();
	return res.send(players);
});

const PORT = process.env.PORT || 7000
app.listen(PORT, (err) => {
  if (err) {
    console.error(`Server Listening Error: ${err.message}`);
  } else {
    console.log(
      `Server running in ${process.env.NODE_ENV} mode on port http://localhost:${PORT}`
      .yellow.bold
    )
  }
})
