<template>
<div>
   <app-video v-if="rutas.video"  :direccionVideo="rutaVideo"></app-video>
  <app-inicio v-if="rutas.inicio"></app-inicio>
</div>

</template>
   
<script>

import io from 'socket.io-client';
import video from "./video.vue";
import inicio from "./inicio.vue";
export default {
  name: "Api",
  data() {
    return {
      rutas: {
        video:false,
        inicio:true
      },
      socket:io.connect('http://192.168.1.78:3333', { 'forceNew': true }),
      rutaVideo:""
    };
  },
  computed: {},
  methods: {
    
  },
  mounted: function() {
    
    
this.socket.on('messages', function(data) {

      console.log(data.value);
     

    if (data.value== "nivel0") {
     
     this.rutas={
       video:false,
       inicio:false
     }

     this.rutas["inicio"]=true;
    }

    if (data.value == "nivel1") {
      
      this.rutaVideo = "/videos/video1.mp4";
      
     this.rutas={
       video:false,
       inicio:false
     }

     this.rutas["video"]=true;


    }

    if (data.value == "nivel2") {
      
      this.rutaVideo = "/videos/video2.mp4";
      
     this.rutas={
       video:false,
       inicio:false
     }

     this.rutas["video"]=true;
    }

    if (data.value == "nivel3") {
      
      this.rutaVideo ="/videos/video3.mp4";
      
     this.rutas={
       video:false,
       inicio:false
     }

     this.rutas["video"]=true;
    }

	
}.bind(this));


  },
  created: function() { },
  components: {
    'app-video':video,
    'app-inicio':inicio,
  }
};
</script>

<style scoped>

video { 
  margin: 0px; 
  padding: 0px; 
  height: 100%; 
  border: none;
  background-color: #000; 
} 

video {
  display: block;       /* iframes are inline by default */
  background: #000;
  border: none;         /* Reset default border */
  height: 90vh;        /* Viewport-relative units */
  width: 90vw;
}

.container{
  background-color: #000;
  height: 100vh; 
}
.row{
  background-color: #000; 
}
.app{
  background-color: #000; 
}

.img-class{
  margin-top: 25%;
  margin-left: 25%;
}
</style>