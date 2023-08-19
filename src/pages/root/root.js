import logo from '../../logo.svg';
import './root.css';
import { useNavigate } from "react-router-dom";
import Dashboard from '../dashboard/dashboard';

function Root() {
  const navigate = useNavigate();

  return (
    <body>
      <div className="App">
        <div className="App-header">
          <img src={logo} className="App-logo" alt="logo" />
        </div>
        <div>
          <button onClick={() => navigate("/")}>Go to Root</button>
          <button onClick={() => navigate("/dashboard")}>Go to Dashboard</button>
        </div>
      </div>
    </body>
  );
}

export default Root;