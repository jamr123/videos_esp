
var IO;

function socketSend(io){

    IO=io;

}

function dpslog(req,res){

console.log(req.body.dato);
IO.emit("messages", {value:req.body.dato});
res.status(200).send({
    estado: "OK"
});

}



module.exports = {
    dpslog,
    socketSend,
}