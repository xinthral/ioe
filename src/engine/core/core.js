import './core.css';
import CircleProgressBar from '../../UI/elements/CircleProgressBar';
import Logo from '../../logo.svg';

import React, { useEffect, useState } from 'react';

function GameComponent() {
  const [gameState, setGameState] = useState(0);
  const ProgressIcon = (<svg width="40" height="40">{Logo}</svg>);
  let count = 0;

   useEffect(() => {
    let animationFrameId;

    const gameLoop = () => {
      // Update game state and perform calculations/animations

      // Call setState to trigger a re-render
      setGameState(0);

      // Call requestAnimationFrame to create a continuous loop
      animationFrameId = requestAnimationFrame(gameLoop);
    };

    // Start the game loop
    animationFrameId = requestAnimationFrame(gameLoop);

    // Clean up the game loop when the component unmounts
    return () => {
      cancelAnimationFrame(animationFrameId);
    };
  }, []);

  return (
    // Render your game component using the game state
    <div className='gamePane'>
      {/* Your game component */}
      <p>Game Pane</p>
      <div className='UIElementProgressCircle'>
        <CircleProgressBar progress={count += 5} icon={ProgressIcon} size={100} />
      </div>
    </div>
  );
}

export default GameComponent;