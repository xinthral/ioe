const tableNames = require('../structures/tableNames');
const createQueries = require('../structures/createQueries');

export default createPlayers = () => {
    /*! Players Table */
    tableNames.push('players');
    var createPlayerQuery = `CREATE TABLE IF NOT EXISTS ${tableNames[0]} (` +
        'uid VARCHAR(32) UNIQUE PRIMARY KEY NOT NULL, ' +
        'username VARCHAR(16), ' +
        'firstname VARCHAR(16), ' +
        'surname VARCHAR(32), ' +
        'bio TEXT' +
        ');'
    createQueries.push(createPlayerQuery);
};