import React from 'react';
import Button from 'react-bootstrap/Button';
import Col from 'react-bootstrap/Col';
import Row from 'react-bootstrap/Row';
import { useDispatch } from 'react-redux';
import { deletePlayerAsync, completePlayerAsync, incrementPlayerLevelAsync } from '../../redux/playerSlice';

const PlayerItem = ({ id, name, level, completed }) => {
	const dispatch = useDispatch();

	const handleCheckboxClick = () => {
		dispatch(completePlayerAsync({ id, completed: !completed }));
	}

	const handleDeleteClick = () => {
		dispatch(deletePlayerAsync({ id }));
	}

	const handleDecrementClick = () => {
		dispatch();
	}

	const handleIncrementClick = () => {
		dispatch(incrementPlayerLevelAsync({ id, level: level += 1 }));
	}

	return (
		<li className={`list-group-item ${completed && 'list-group-item-success'}`}>
			<div className='d-flex justify-content-between'>
				<span className='d-flex align-items-center'>
					<input
						type='checkbox'
						className='mr-3'
						checked={completed}
						onClick={handleCheckboxClick}
					></input>
					<Row className={{display: 'flex', justifyContent: 'center'}}>
						<Col sm="auto">{ name }</Col>
						<Col sm="auto">{ level }</Col>
						<Col>{ id }</Col>
					</Row>
					
				</span>
				<Button onClick={handleDecrementClick} className='btn btn-secondary'>
					Level-
				</Button>
				<Button onClick={handleIncrementClick} className='btn btn-secondary'>
					Level+
				</Button>
				<Button onClick={handleDeleteClick} className='btn btn-danger'>
					Delete
				</Button>
			</div>
		</li>
	);
};

export default PlayerItem;