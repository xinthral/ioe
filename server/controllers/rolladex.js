// Import database
const knex = require('./../db')
let db1 = 'rolladex'

// Retrieve all users from the database
exports.usersAll = async (req, res) => {
  knex
    .select('*')
    .from(db1)
    .then(userData => {
      res.json(userData)
    })
    .catch((error) => {
        res.json({message: `There was an error: ${error}.`})
    })
}

// Create New User
exports.userCreate = async (req, res) => {
  knex(db1)
    .insert({
      'username': req.body.username,
      'nickname': req.body.nickname,
      'rating':   req.body.rating
    })
    .then(() => {
      res.json({ messsage: `User \'${req.body.username}\' entered.`})
    })
    .catch((error) => {
      res.json({ message: `There was an error: ${error}`})
    })
}

exports.userDelete = async (req, res) => {
  knex(db1)
    .where('id', req.body.id)
    .del()
    .then(() => {
      res.json({ message: `User ${req.body.id} deleted.` })
    })
    .catch((error) => {
      res.json({ message: `There was an error: ${error}`})
    })
}

exports.userPurge = async (req, res) => {
  knex
    .select('*')
    .from(db1)
    .truncate()
    .then(() => {
      res.json({ message: `User Table ${db1} has been truncated.`})
    })
    .catch((error) => {
      res.json({ message: `There was an error: ${error}`})
    })
}
// exports.userCreate = async (req, res) => {
//   knex(db1)
//     .then(() => {})
//     .catch((error) => {
//       res.json({ message: `There was an error: ${error}`})
//     })
// }