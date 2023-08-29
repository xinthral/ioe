import React from 'react';
import AddPlayerForm from '../../components/players/AddPlayerForm';
import Navigation from '../../components/ui/navbars/Navigation';
import PlayerList from '../../components/players/PlayerList';

class PlayerLanding extends React.Component {
    reRender = () => { this.forceUpdate(); }

    render() {
        return (
            <>
                <Navigation />
                <div className='container bg-white p-4 mt-5'>
                    <h1>Player List</h1>
                    <AddPlayerForm />
                    <PlayerList />
                </div>
            </>
        );
    }
}

export default PlayerLanding;