const functions = require('firebase-functions');

// // Create and Deploy Your First Cloud Functions
// // https://firebase.google.com/docs/functions/write-firebase-functions
//
const admin = require('firebase-admin')
admin.initializeApp(functions.config().firebase);
const database = admin.database();
exports.helloiot = functions.https.onRequest(async(request, response) => {
    let params = request.body.queryResult.parameters;
    console.log("params are ", params)

    await database.ref().update(params)

 response.send("Hello from Google Asistant IOT bot!");
});
