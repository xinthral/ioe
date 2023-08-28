import React from 'react';
import 'bootstrap/dist/css/bootstrap.min.css';
import AddTodoForm from         '../components/todos/AddTodoForm';
import TodoList from            '../components/todos/TodoList';
import TotalCompleteItems from  '../components/todos/TotalCompleteItems';
import Navigation from          '../components/ui/navbars/Navigation';

const MainPage = () => {
	return (
        <>
            <Navigation />
            <div className='container bg-white p-4 mt-5'>
                <h1>My Todo List</h1>
                <AddTodoForm />
                <TodoList />
                <TotalCompleteItems />
            </div>
        </>
	);
};

export default MainPage;