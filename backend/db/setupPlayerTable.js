const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database(':memory:');
const { nanoid } = require('nanoid');

var tableName = 'players';
// var dummyData = [
//     [nanoid(), 'xTestUser-1', 'Xtest', 'User1', 'Kickin it old school.'],
//     [nanoid(), 'xTestUser-2', 'testX', 'User2', 'Flowin like its cool.'],
//     [nanoid(), 'xTestUser-3', 'teXst', 'User3', 'Feelin like the fool.'],
// ];

db.serialize(() => {
    //! Create Database and Schema
    let createQuery = `CREATE TABLE IF NOT EXISTS ${tableName} (` +
        'uid VARCHAR(32) PRIMARY KEY NOT NULL, ' +
        'username VARCHAR(16), ' +
        'firstname VARCHAR(16), ' +
        'surname VARCHAR(32), ' +
        'bio TEXT' +
        ');'
    db.run(createQuery, (err) => {
        if (err) {
            console.error('Error create table: ', err.message);
        } else {
            console.log(`Created ${tableName} successfully.`);
        }
    });

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
        console.log(`Connection to ${tableName} closed.`);
    }
});