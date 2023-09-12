const express = require('express')
const { protect } = require('../middleware/authMiddleware.js')
const userController = require('../controllers/userController.js')

const router = express.Router()

router.post('/register', userController.registerUser)
router.post('/login', userController.loginUser)
router.route('/profile').get(protect, userController.getUserProfile)

module.exports = router
