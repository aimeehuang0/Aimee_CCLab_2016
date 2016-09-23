var BookName = '';
var APIKey = '63e763062be34e67b1948d52e0c2a0fb';


//init
var init = function(){
  console.log("Hello World!");

  $("#inpt_search").on('focus', function () {
    $(this).parent('label').addClass('active');
  });

  $("#inpt_search").on('blur', function () {
    if($(this).val().length == 0)
      $(this).parent('label').removeClass('active');
  });


  $('#searchBook').keypress(function (e) {
  if (e.which == 13) {
    event.preventDefault();
    BookName = $("#inpt_search").val();
    getBookReview();
  }
  });
}

var loadBook = function(jsonResponse){
  console.log(jsonResponse);
  if (jsonResponse.num_results == 0){
      alert("no Result");
      return;
  }
  else{
      for (var i = 0; i <jsonResponse.num_results ; i++) {
        // console.log(jsonResponse.results[i]);
        var reviewURL = jsonResponse.results[i].url;
        var reviewAuthor = jsonResponse.results[i].byline;
        var publication_dt = jsonResponse.results[i].publication_dt;
        var book_title = jsonResponse.results[i].book_title;
        var book_author = jsonResponse.results[i].book_author;
        var summary = jsonResponse.results[i].summary;
        // console.log(i + " " +reviewURL+ " "+reviewAuthor+" "+summary);
        $('.bookDesc').append(
          $('<div/>')
            // .attr("id", "newDiv1")
            .addClass("bookReview")
            .append("<div/>")
            .html("Book Title:" + book_title + '<br>'+"Book Author: "+book_author + "<br> Publication Date: "+publication_dt + "<br> Publication Date: "+publication_dt + "<br> Review Author: "+reviewAuthor + "<br> Review Summary: "+summary + "<br> URL: "+reviewURL)
        );
  }  
}

var getBookReview = function(){
  var myUrl = "http://api.nytimes.com/svc/books/v3/reviews.json?title=1q84" ;//+ BookName;
  // console.log(myUrl);

  $.ajax({
    url:myUrl,
    dataType: "json",
    success: function(response){
      console.log("i got the json file parsed!");
      loadBook(response);
    }
  });
}


$(document).ready(function() {
  //init();
  getBookReview();
});
