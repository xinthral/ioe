const tableNames = require('../structures/tableNames');
const createQueries = require('../structures/createQueries');

export default createToons = () => {
    /*! Toons Table */
    tableNames.push('toons');
    var createToonQuery = `CREATE TABLE IF NOT EXISTS ${tableNames[1]} (` +
        'uid VARCHAR(32) PRIMARY KEY NOT NULL, ' +
        'name VARCHAR(16) NOT NULL, ' +
        'level INTEGER DEFAULT(0), ' +
        'ownedBy VARCHAR(32), ' +
        `FOREIGN KEY (ownedBy) REFERENCES ${tableNames[0]}(uid)` +
        ');'
    createQueries.push(createToonQuery)
};