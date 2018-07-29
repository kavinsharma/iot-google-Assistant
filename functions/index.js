const functions = require('firebase-functions');
var admin = require('firebase-admin');
admin.initializeApp(functions.config().firebase);

var database = admin.database();
// // Create and Deploy Your First Cloud Functions
// // https://firebase.google.com/docs/functions/write-firebase-functions
//
 exports.hello = functions.https.onRequest((request, response) => {
  
	let params = request.body.result.parameters;
	database.ref().set(params);

	response.send({

	speech: "Light controlled successfully"
});
 });
