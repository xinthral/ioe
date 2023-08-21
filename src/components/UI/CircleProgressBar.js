import React, { useState, useEffect } from 'react';
import PropTypes from 'prop-types';
import './CircleProgressBar.css'; // Import or create your CSS for styling

const CircleProgressBar = ({ progress, icon, size }) => {
  // State to hold the current progress value
  const [currentProgress, setCurrentProgress] = useState(progress);
  const radius = size / 2;
  // Calculate the dash-offset for the progress circle
  const circumference = 2 * Math.PI * (size / 2);
  const progressOffset = circumference - (currentProgress / 100) * circumference;
  
  useEffect(() => {
    // Timer to update progress by 5 every second
    const timer = setInterval(() => {
      setCurrentProgress(prevProgress => (prevProgress + 5) % 101); // Ensure progress doesn't exceed 100
    }, 1000);
    
    // Cleanup on unmount
    return () => {
      clearInterval(timer);
    };
  }, []); // Run effect only on mount
  
  return (
    <div className="circle-progress-bar">
      <svg width={size} height={size}>
        {/* Outer Circle (Progress Bar) */}
        <circle
          className="outer-circle"
          cx={size / 2}
          cy={size / 2}
          r={size / 2 - 10}
          strokeDasharray={circumference}
          strokeDashoffset={progressOffset}
        />

        {/* Inner Circle (Icon) */}
        <circle className="inner-circle" cx={radius} cy={radius} r={radius - 10} />
        
        {/* Icon */}
        <foreignObject
          x={0}
          y={0}
          width={size}
          height={size}
          className="icon-container"
        >
          {icon}
        </foreignObject>
      </svg>
    </div>
  );
};

CircleProgressBar.propTypes = {
  progress: PropTypes.number.isRequired,
  icon: PropTypes.element.isRequired,
  size: PropTypes.number.isRequired,
};

export default CircleProgressBar;











//   return (
//     <div className="circle-progress">
//       <svg width={size} height={size}>
//         {/* Render the progress circle */}
//         <circle
//           className="circle-progress-bar"
//           cx={size / 2}
//           cy={size / 2}
//           r={size / 2 - 10}
//           strokeDasharray={circumference}
//           strokeDashoffset={offset}
//         />
//         {/* Render the icon */}
//         <foreignObject width={size} height={size}>
//           <div className="circle-icon">{icon}</div>
//         </foreignObject>
//       </svg>
//       <div className="progress-number">{currentProgress}%</div>
//     </div>
//   );
// };
