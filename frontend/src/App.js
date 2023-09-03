import React from 'react';
import 'bootstrap/dist/css/bootstrap.min.css';
import MainPage from './pages/main';
import TodoLanding from './pages/todos/landing';
import SignUp from './pages/login/landing';
import PlayerLanding from './pages/players/landing';
import { createBrowserRouter, RouterProvider} from 'react-router-dom';

const router = createBrowserRouter([
	{path: "/", element: <MainPage />,},
	{path: "/todos", element: <TodoLanding />},
	{path: "/players", element: <PlayerLanding />},
	{path: "/signup", element: <SignUp />},
]);

const App = () => {
	return (<RouterProvider router={router} />);
};

export default App;