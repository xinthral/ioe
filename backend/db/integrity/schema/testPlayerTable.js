/*!
 * Ensure the integrity of the Player Schema
 * [uid, username, firstname, surname, bio]
*/
const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database('./ioe.db');
const { nanoid } = require('nanoid');
const tableNames = require('../../structures/tableNames');
const tableWeaver = require('../../setup/tableWeaver');
const tableIdx = 0;

//! Setup Table Schema
tableWeaver;

//! Display Dummy Data
var dummyData = [
    [nanoid(), 'xTestUser-1', 'Xtest', 'User1', 'Kickin it old school.'],
    [nanoid(), 'xTestUser-2', 'testX', 'User2', 'Flowin like its cool.'],
    [nanoid(), 'xTestUser-3', 'teXst', 'User3', 'Feelin like the fool.'],
];

db.serialize(() => {
    // ! Implement Dummy Data
    const stmt = db.prepare(`INSERT INTO ${tableNames[tableIdx]} VALUES (?, ?, ?, ?, ?)`);
    for (let i = 0 ; i < dummyData.length; i++) {
        stmt.run(dummyData[i]);
    }
    stmt.finalize();
    
    // ! Display what was ingested
    db.each(`SELECT rowid AS id, uid, username, firstname, surname, bio from ${tableNames[tableIdx]}`, (err, row) => {
        console.log(`${row.id} :${row.uid}: ${row.firstname}-${row.surname} ${row.bio}`);
    });
});

//! Close Database Connection
db.close((err) => {
    if (err) {
        console.error('Error closing connection:', err.message);
    } else {
        console.log(`Connection to ${tableNames[tableIdx]} closed.`);
    }
});