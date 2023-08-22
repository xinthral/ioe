import React, { setState } from 'react';
import FetchUrl from './utilz/fetchUrl'

class Home extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      data: '',
    }
  }
  
  querySite = () => {
    setState({data: FetchUrl('www.xinthral.com')});
  }

  render() {
    return( 
      <>
        <h1>Home</h1>;
        <button onClick={this.querySite}>Try Me!</button>
        <div>
          {this.state.data && this.state.data.map((item) => {
            return <p key={item.id}>{item.title}</p>;
          })}
        </div>
      </>
    )
  }
};

export default Home;