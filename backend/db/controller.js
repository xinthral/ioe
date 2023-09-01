const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database('./ioe.db');
const setupTables = require('./setup/tableWeaver');
const testPlayerTable = require('./integrity/schema/testPlayerTable');
const testToonTable = require('./integrity/schema/testToonTable');

const RunItSon = () => {
    //! Setup Table
    setupTables;
    
    //! Test Tables
    testPlayerTable;
    testToonTable;
};

exports.module = RunItSon;