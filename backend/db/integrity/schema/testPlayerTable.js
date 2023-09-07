/*!
 * Ensure the integrity of the Player Schema
 * [uid, username, firstname, surname, bio]
*/
import sqlite3 from 'sqlite3'
import { nanoid } from 'nanoid'
import tableNames from '../../structures/tableNames.js'
import tableWeaver from '../../setup/tableWeaver.js'

sqlite3.verbose()
let db = new sqlite3.Database('./ioe.db');
let tableIdx = 0

function testPlayerSchema() {
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

    console.log('Prepared Player Table Test Statement...');
};

function closePlayerConnection() {
    //! Close Database Connection
    db.close((err) => {
        if (err) {
            console.error('Error closing connection:', err.message);
        } else {
            console.log(`Connection to ${tableNames[tableIdx]} closed.`);
        }
    });
};

module.exports = {testPlayerSchema, closePlayerConnection};