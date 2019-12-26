'use strict'
const app = require("./app");
const server = require('http').Server(app);
const config = require("./config");
const SocketIo = require('socket.io');
const io = SocketIo.listen(server);
var socketConsumer = require('./controladores/dps').socketSend(io);


server.listen(config.PORT, () => {
  console.log(`Api corriendo en el puerto ${config.PORT}`);
  
});



