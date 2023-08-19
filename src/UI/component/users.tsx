// Import deps
import React, { useEffect, useState } from 'react'
import axios from 'axios'

// Import components
import { UserList } from './user-list'

// Import styles
import './../styles/bookshelf.css'

// Create Bookshelf component
export const Users = () => {
  // Prepare states
  const [username, setUsername] = useState('')
  const [nickname, setNickname] = useState('')
  const [rating, setRating] = useState('')
  const [users, setUsers] = useState([])
  const [loading, setLoading] = useState(true)

  // Fetch all books on initial render
  useEffect(() => {
    fetchBooks()
  }, [])

  // Fetch all books
  const fetchBooks = async () => {
    // Send GET request to 'books/all' endpoint
    axios
      .get('http://localhost:4001/users/all')
      .then(response => {
        // Update the books state
        setUsers(response.data)

        // Update loading state
        setLoading(false)
      })
      .catch(error => console.error(`There was an error retrieving the book list: ${error}`))
  }

  // Reset all input fields
  const handleInputsReset = () => {
    setUsername('')
    setNickname('')
    setRating('')
  }

  // Create new book
  const handleBookCreate = () => {
    // Send POST request to 'books/create' endpoint
    axios
      .post('http://localhost:4001/user/create', {
        username: username,
        nickname: nickname,
        rating: rating
      })
      .then(res => {
        console.log(res.data)

        // Fetch all books to refresh
        // the books on the bookshelf list
        fetchBooks()
      })
      .catch(error => console.error(`There was an error creating the ${username} account: ${error}`))
  }

  // Submit new book
  const handleUserSubmit = () => {
    // Check if all fields are filled
    if (username.length > 0 && nickname.length > 0 && rating.length > 0) {
      // Create new book
      handleBookCreate()

      console.info(`User ${username} referred to as ${nickname}, saved.`)

      // Reset all input fields
      handleInputsReset()
    }
  }

  // Remove book
  const handleUserRemove = (id: number, username: string) => {
    // Send PUT request to 'books/delete' endpoint
    axios
      .put('http://localhost:4001/user/delete', { id: id })
      .then(() => {
        console.log(`User ${username} removed.`)

        // Fetch all books to refresh
        // the books on the bookshelf list
        fetchBooks()
      })
      .catch(error => console.error(`There was an error removing the ${username} account: ${error}`))
  }

  // Reset book list (remove all books)
  const handleListReset = () => {
    // Send PUT request to 'books/reset' endpoint
    axios.put('http://localhost:4001/user/reset')
    .then(() => {
      // Fetch all books to refresh
      // the books on the bookshelf list
      fetchBooks()
    })
    .catch(error => console.error(`There was an error resetting the user list: ${error}`))
  }

  return (
    <div className="book-list-wrapper">
      {/* Form for creating new book */}
      <div className="book-list-form">
        <div className="form-wrapper" onSubmit={handleUserSubmit}>
          <div className="form-row">
            <fieldset>
              <label className="form-label" htmlFor="username">Enter username:</label>
              <input className="form-input" type="text" id="username" name="username" value={username} onChange={(e) => setUsername(e.currentTarget.value)} />
            </fieldset>

            <fieldset>
              <label className="form-label" htmlFor="nickname">Enter Nickname:</label>
              <input className="form-input" type="text" id="nickname" name="nickname" value={author} onChange={(e) => setNickname(e.currentTarget.value)} />
            </fieldset>
          </div>

          <div className="form-row">
            <fieldset>
              <label className="form-label" htmlFor="rating">Enter rating:</label>
              <input className="form-input" type="text" id="rating" name="rating" value={rating} onChange={(e) => setRating(e.currentTarget.value)} />
            </fieldset>
          </div>
        </div>

        <button onClick={handleUserSubmit} className="btn btn-add">Add User</button>
      </div>

      {/* Render bookshelf list component */}
      <UserList users={users} loading={loading} handleUserRemove={handleUserRemove} />

      {/* Show reset button if list contains at least one book */}
      {users.length > 0 && (
        <button className="btn btn-reset" onClick={handleListReset}>Reset User list.</button>
      )}
    </div>
  )
}