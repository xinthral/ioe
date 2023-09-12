// database connection file to MongoDB
// const { mongoose } = require('mongoose')

// const temp = 'mongodb+srv://xadmin:6nY2Swwah8%26Y%3Ax%22K@ioe.y7guakn.mongodb.net/?retryWrites=true&w=majority'

// const connectDB = async () => {
//   try {
//     // const conn = await mongoose.connect(process.env.MONGO_URI, {
//     const conn = await mongoose.connect(temp, {
//       useUnifiedTopology: true,
//       useNewUrlParser: true,
//     })
//     console.log(`mongodb connected: ${conn.connection.host}`.cyan.underline)
//   } catch (error) {
//     console.log(`Error: ${error.message}`.underline.bold)
//     process.exit(1)
//   }
// }

// module.exports = connectDB