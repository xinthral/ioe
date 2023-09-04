/*!
 * Ensure the integrity of the Player Schema
 * [uid, name, level, fuid]
*/
const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database('./ioe.db');
const { nanoid } = require('nanoid');
const tableNames = require('../../structures/tableNames');
const tableWeaver = require('../../setup/tableWeaver');
const tableIdx = 1;

var tmpids = ['AussdATQXDaWEAnHx5LU8', '43790jY-1pahg2ND9-vYU', '1-3VNV8wIvUulD8Y1CLWC', 'y_to43uTjVajJs8M03T44']

function TestToonSchema() {
    //! Display Dummy Data
    var dummyData = [];
    
    for (let step = 0; step < tmpids.length; step++) {
        dummyData.push([nanoid(), `xTestUser-${step}`, 1, `${tmpids[step]}`]);
    };
    
    console.log('Preparing Toon Table Statement...');

    db.serialize(() => {
        // ! Implement Dummy Data
        const stmt = db.prepare(`INSERT INTO ${tableNames[tableIdx]} VALUES (?, ?, ?, ?)`);
        for (let i = 0 ; i < dummyData.length; i++) {
            stmt.run(dummyData[i]);
        }
        stmt.finalize();
        
        // ! Display what was ingested
        db.each(`SELECT rowid AS id, uid, name, level FROM ${tableNames[tableIdx]}`, (err, row) => {
            console.log(`${row.id} :${row.uid}: ${row.name}-${row.level}`);
        });
    });
};

function closeToonConnection() {    
    //! Close Database Connection
    db.close((err) => {
        if (err) {
            console.error('[TestToonTable Error] closing connection:', err.message);
        } else {
            console.log(`Connection to ${tableNames[tableIdx]} closed.`);
        }
    });
};

module.exports = {TestToonSchema, closeToonConnection};