import React from 'react';
import 'bootstrap/dist/css/bootstrap.min.css';
import Navigation from 				'../../components/ui/navbars/Navigation';
import AddTodoForm from 			'../../components/todos/AddTodoForm';
import TodoList from 				'../../components/todos/TodoList';
import TotalCompleteItems from 		'../../components/todos/TotalCompleteItems';
import CircularProgressBar from 	'../../components/ui/progressbars/CircularProgressBar';

const TodoLanding = () => {
	return (
		<>
		<Navigation />
		<div className='container bg-white p-4 mt-5'>
			<h1>My Todo List</h1>
			<AddTodoForm />
			<TodoList />
			<CircularProgressBar icon={'./favicon.ico'} progress={10} />
			<TotalCompleteItems />
		</div>
		</>
	);
};

export default TodoLanding;