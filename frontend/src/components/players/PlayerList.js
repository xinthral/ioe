import React, { useEffect } from 'react';
import { useSelector, useDispatch } from 'react-redux';
import PlayerItem from './PlayerItem';
import { getPlayersAsync } from '../../redux/playerSlice';

const PlayerList = () => {
	const dispatch = useDispatch();
	const players = useSelector((state) => state.players);

	useEffect(() => {
		dispatch(getPlayersAsync());
	}, [dispatch]);

	return (
		<ul className='list-group'>
			{players && players.map((player, uid) => (
				<PlayerItem key={uid} id={player.id} name={player.name} level={player.level} completed={player.completed} />
			))}
		</ul>
	);
};

export default PlayerList;