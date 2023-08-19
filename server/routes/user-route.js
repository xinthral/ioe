// Import express
const express = require('express')

// Import User-Controller
const userRoutes = require('../controllers/rolladex')

// Create Router
const router = express.Router()

// Add route for GET request to retrieve all book
// In server.js, books route is specified as '/books'
// this means that '/all' translates to '/books/all'
router.get('/all', userRoutes.userAll)

// Add route for POST request to create new book
// In server.js, books route is specified as '/books'
// this means that '/create' translates to '/books/create'
router.post('/create', userRoutes.userCreate)

// Add route for PUT request to delete specific book
// In server.js, books route is specified as '/books'
// this means that '/delete' translates to '/books/delete'
router.put('/delete', userRoutes.userDelete)

// Add route for PUT request to reset bookshelf list
// In server.js, books route is specified as '/books'
// this means that '/reset' translates to '/books/reset'
router.put('/reset', userRoutes.userReset)

// Export router
module.exports = router