const jwt = require('jsonwebtoken')

// generate token that expires in 12 hours
const generateToken = (id) => {
  return jwt.sign({ id }, process.env.JWT_SECRET, { expiresIn: '12h' })
}

module.exports = generateToken
