import { useState } from 'react';
import './App.css';
import CircleProgressBar from './components/UI/CircleProgressBar'
import Logo from './logo.svg';

function App() {
  const [icon, setIcon] = useState('');

  return (
    <div className="App">
      <h1>Hello World!</h1>
      <div>
        <CircleProgressBar progress={5} icon={icon} size={50} />
      </div>

    </div>
  );
}

export default App;
