const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database('ioe.db');
const { nanoid } = require('nanoid');
const tableNames = require('../structures/tableNames');
const createQueries = require('../structures/createQueries');
const injestPlayerTable = require('../queries/createPlayerTable');
const injestToonTable = require('../queries/createToonTable');

//! Injest Cached Data 
injestPlayerTable;          // 0
injestToonTable;            // 1

console.log(`Table Names: ${tableNames}`);

//! Create Table Schema's
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
});

//! Close Database Connection
db.close((err) => {
    if (err) {
        console.error('[TableWeaver Error] closing connection:', err.message);
    } else {
        console.log(`Connection to ${tableNames} closed.`);
    }
});