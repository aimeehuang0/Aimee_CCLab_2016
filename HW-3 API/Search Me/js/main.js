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
      $('.bookDesc').empty();
      var book_title = jsonResponse.results[0].book_title;
      var book_author = jsonResponse.results[0].book_author;
       $('.bookDesc').append(
          $('<div/>')
            // .attr("id", "newDiv1")
            .addClass("bookTitle")
            .html(book_title)
        );
        $('.bookDesc').append(
          $('<div/>')
            // .attr("id", "newDiv1")
            .addClass("bookAuthor")
            .html("by "+book_author)
        );


      for (var i = 0; i <jsonResponse.num_results ; i++) {
        // console.log(jsonResponse.results[i]);
        var reviewURL = jsonResponse.results[i].url;
        var reviewAuthor = jsonResponse.results[i].byline;
        var publication_dt = jsonResponse.results[i].publication_dt;
        
        var summary = jsonResponse.results[i].summary;

        

        $('.bookDesc').append(
          $('<div/>')
            // .attr("id", "newDiv1")
            .addClass("bookReview")
            .append("<table/>")
            .html("<tr><td> Review Author: </td><td>"+reviewAuthor + "</td><tr><td>Date:</td><td> "+publication_dt + "</td><tr><td>Review Summary: </td><td>"+summary + "</td><tr><td>URL: </td><td><a href="+reviewURL+">"+reviewURL+"</a></td></tr>")
        );
      }     

  }  
}

var getBookReview = function(){
  var myUrl = "http://api.nytimes.com/svc/books/v3/reviews.json?title="+ BookName;
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
  init();
  //getBookReview();
});
