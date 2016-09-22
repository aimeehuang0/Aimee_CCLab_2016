var controller = new ScrollMagic.Controller({
  globalSceneOptions: {
      triggerHook: "onLeave"
  }
});

/*only for logo*/
var tweenHi = new TimelineMax()
  .add([
      TweenMax.from(".scroll-name div", 2, {
        y: 0,
        ease: Back.ease
      }),
      TweenMax.to(".scroll-name div", 2, {
        y: -500,
        ease: Back.ease
      })
   ]);

var sceneHi = new ScrollMagic.Scene({
    duration: '100%'
  })
  .setTween(tweenHi)
  .setPin(".scroll-name")
  .addTo(controller);


var scene = new ScrollMagic.Scene({
  triggerElement: "#MyProject", // point of execution
  duration: $(window).height()-200, // pin element for the window height - 1
  triggerHook: 0, // don't trigger until #pinned-trigger1 hits the top of the viewport
})

.setPin("#AllProject")
.addTo(controller); // the element we want to pin

// var scene = new ScrollMagic.Scene({triggerElement: "#MyTeam"})
//           .addIndicators() 
//           .addTo(controller);
