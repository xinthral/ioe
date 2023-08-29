const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database('ioe.db');
const { nanoid } = require('nanoid');

//! Dummy Data sets
var tableNames = [];
var createQueries = [];

// var dummyPlayerData = [
//     [nanoid(), 'xTestUser-1', 'Xtest', 'User1', 'Kickin it old school.'],
//     [nanoid(), 'xTestUser-2', 'testX', 'User2', 'Flowin like its cool.'],
//     [nanoid(), 'xTestUser-3', 'teXst', 'User3', 'Feelin like the fool.'],
// ];
tableNames.push('players')
var createPlayerQuery = `CREATE TABLE IF NOT EXISTS ${tableNames[0]} (` +
    'uid VARCHAR(32) PRIMARY KEY NOT NULL, ' +
    'username VARCHAR(16), ' +
    'firstname VARCHAR(16), ' +
    'surname VARCHAR(32), ' +
    'bio TEXT' +
    ');'
createQueries.push(createPlayerQuery)

tableNames.push('toons');
var createToonQuery = `CREATE TABLE IF NOT EXISTS ${tableNames[1]} (` +
    'uid VARCHAR(32) PRIMARY KEY NOT NULL, ' +
    'name VARCHAR(16) NOT NULL, ' +
    'level INTEGER DEFAULT(0)' +
    ');'
createQueries.push(createToonQuery)

//! Create Player Table Schema
db.serialize(() => {
    for (let i = 0; i < createQueries.length; i++) {
        db.run(createQueries[i], (err) => {
            if (err) {
                console.error(`Error creating ${tableNames[i]}: `, err.message);
            } else {
                console.log(`Created table ${tableNames[i]} successfully.`);
            }
        });
    }

    //! Implement Dummy Data
    // const stmt = db.prepare(`INSERT INTO ${tableName} VALUES (?, ?, ?, ?, ?)`);
    // for (let i = 0 ; i < dummyData.length; i++) {
    //     stmt.run(dummyData[i]);
    // }
    // stmt.finalize();

    //! Display what was ingested
    // db.each(`SELECT rowid AS id, uid, username, firstname, surname, bio from ${tableName}`, (err, row) => {
    //     console.log(`${row.id} :${row.uid}: ${row.firstname}-${row.surname} ${row.bio}`);
    // });
});


//! Close Database Connection
db.close((err) => {
    if (err) {
        console.error('Error closing connection:', err.message);
    } else {
        console.log(`Connection to ${tableNames} closed.`);
    }
});