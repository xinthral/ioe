// Import path module
const { error } = require('console');
const path = require('path')

// Get the location of database.sqlite file
const dbPath = path.resolve(__dirname, 'db/library.db')

// Create connection to SQLite database
const knex = require('knex')({
  client: 'sqlite3',
  connection: {
    filename: dbPath,
  },
  useNullAsDefault: true
})

// Create a table in the database
let databaseName = 'rolladex';
knex.schema
  .hasTable(databaseName)
    .then((exists) => {
      if (!exist) {
        // If no "books" table exists
        // create new, with "id", "author", "title",
        // "pubDate" and "rating" columns
        // and use "id" as a primary identification
        // and increment "id" with every new record (book)
        return knex.schema.creatTable(databaseName, (table) => {
            table.increments('id').primary()
            table.string('username')
            table.string('nickname')
            table.integer('rating')
        })
        .then(() => {
            // Log Table Success
            console.log(`Table ${databaseName} Created!`)
        })
        .catch((error) => {
            // Log Table Error 
            console.error(`There was an error creating table: ${error}`)
        })
      }
    })
    .then(() => {
        // Log Database Success
        console.log('Database created successfully!')
    })
    .catch((error) => {
        // Log Databse Errors
        console.error(`Failed to create database!: ${error}`)
    })

// Debugging
// Log All Data
knex.select('*').from(databaseName)
  .then(data => console.log(`Data: ${data}`))
  .catch(err => console.error(`Failed to display: ${error}`))

module.exports = knex