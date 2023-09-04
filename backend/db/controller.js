const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database('./ioe.db');
const setupTables = require('./setup/tableWeaver');
const {testPlayerSchema} = require('./integrity/schema/testPlayerTable');
const {TestToonSchema} = require('./integrity/schema/testToonTable');

const RunItSon = () => {
    //! Setup Table
    console.log('Setting up Tables...');
    setupTables();
    
    //! Test Tables
    console.log('Testing Tables...');
    testPlayerSchema();
    TestToonSchema();
};

module.exports = RunItSon;