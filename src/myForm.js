import { useState } from 'react';

function MyForm() {
  const [name, setName] = useState('');
  const [email, setEmail] = useState('');
  return(
    <form>
      <label>Name:|
        <input
          type='text'
          value={name}
          onChange={(e) => setName(e.target.value)}
        />
      </label>
      <br />
      <label>Email: |
        <input
          type='email'
          value={email}
          onChange={(e) => setEmail(e.target.value)}
        />
      </label>
    </form>
  )
}

export default MyForm;