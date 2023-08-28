// CircularProgressBar.js
import React from 'react';
import { connect } from 'react-redux';
import './CircularProgressBar.css';

const CircularProgressBar = ({ icon, progress }) => {
  return (
    <div className="progress-circular-bar">
      <svg className="progress-circle" width="50" height="50">
        <circle
          className="progress-circle-track"
          cx="25"
          cy="25"
          r="22"
        >
          <img src={icon} />
        </circle>
        <circle
          className="progress-circle-bar"
          cx="25"
          cy="25"
          r="22"
          style={{ '--progress': progress }}
        />
      </svg>
    </div>
  );
};

const mapStateToProps = (state) => ({
  progress: state.progress, // Assuming you have progress in your Redux state
});

export default connect(mapStateToProps)(CircularProgressBar);