function search_ajax_call(){function b(b,c){if(c==="success")var d=this.id;else var d=$.now();var e=$("#search-dropdown").attr("timestamp");if(e===undefined||e<d)b.html=$.trim(b.html),$("#search-dropdown").html(b.html),b.html.length>0&&$("#search-dropdown").show(),$("#results-more .no-results").hide(),$("#results-more #search-more").show(),$("#search-dropdown").attr("timestamp",d),window.search_suggestions_data=b;window.cached_search_results[a]=b}var a=$("#searchbar-input").val();if(!is_user_logged_in&&a.length===0){$("#search-dropdown").hide();return}window.cached_search_results||(window.cached_search_results={}),$("#search-dropdown").html()?($("#results-more #search-more").hide(),$("#results-more").show(),$("#results-more .no-results").show()):($("#search-dropdown").html("<div class=\"result-wrapper-banner1\"></div><div class=\"result-wrapper-banner2\"></div><div class=\"result-wrapper-container\"><div id='results-more' class='result-wrapper'><div class='text-div no-results'><div id='text' class='bold float-left'> Retrieving suggestions </div><div id='image' class='dots-loader float-left'></div> <div class='clear'></div></div></div></div>"),$("#search-dropdown").show());if(a in window.cached_search_results)return b(window.cached_search_results[a]),!0;$.ajax({url:$("#searchbar-input").attr("ajax1"),type:"GET",data:{q:a,randfloat:randfloat},id:$.now(),cache:!0}).done(b).fail(function(){console.log(arguments),$("#search-dropdown").hide()})}function set_first_result_focused(){var a=$("#search-dropdown").find(".focused");if(a.length===0){var b=$("#search-dropdown").find(".result-wrapper").first();b&&!b.hasClass("no-results")&&b.addClass("focused")}}var randfloat=Math.random();$("#searchbar-input").live("keyup",function(a){var b=$(this).attr("ajax1"),c=$(this).val(),d=String.fromCharCode(a.keyCode),e=d.match(/\w/);if(!e&&a.keyCode!==40&&a.keyCode!==13&&a.keyCode!==8&&a.keyCode!==27)return console.log("input element key handled"),!0;if(a.keyCode===27)return $(this).blur(),$("#search-dropdown").hide(),!0;if(a.keyCode===40||a.keyCode===13)return window.search_suggestions_data&&$("#search-dropdown").css("display")==="none"&&($("#search-dropdown").show(),$(".focused").removeClass("focused"),$(".result-wrapper").first().addClass("focused")),!0;search_ajax_call()}),$("#searchbar-input").live("keydown",function(a){dropdown(a)});var dropdown=function(a){if($("#search-dropdown").css("display")==="none")return!1;if(a.keyCode===39){var b=$(".focused").find("a").attr("data-q");$("#searchbar-input").focus().val(b),search_ajax_call()}if(a.keyCode===40){var c=$(".focused"),d=$(".result-wrapper:not(:hidden)");if(c.length<1)d.first().addClass("focused");else{var e=c.index(),f=(e+1)%d.length;c.toggleClass("focused"),$(d[f]).toggleClass("focused")}return!0}if(a.keyCode===38){var c=$(".focused"),d=$(".result-wrapper:not(:hidden)");if(c.length<1)d.last().addClass("focused");else{var e=c.index(),f=e-1;f<0&&(f=d.length-1),c.toggleClass("focused"),$(d[f]).toggleClass("focused")}return!0}if(a.keyCode===13){var b=$(".focused").find("a").attr("data-q");$("#searchbar-input").focus().val(b),$(".focused").find("a")[0].click()}};$("body").mouseup(function(a){$(a.target).parents("#search-dropdown").length===0&&$(a.target).parents("#searchbar-input").length===0&&!$("#searchbar-input").is(":focus")&&$("#search-dropdown").hide()}),$(".result-wrapper").live("mouseover",function(){$(".focused").removeClass("focused"),$(this).addClass("focused")}),$(".result-wrapper").live("mouseout",function(){$(this).removeClass("focused")}),$("#searchbar #search-icon-container").live("click",function(){if($("#searchbar-input").val().length>0){var a=$("#url_search_page").attr("href");a!=undefined&&(a=a+"?q="+$("#searchbar-input").val(),window.location=a)}return!1}),$(document).live("keyup",function(a){var b=$("#searchbar-input");$(":focus").length===0&&a.keyCode===191&&b.focus().val(b.val())}),$("#searchbar-input").live("focus",function(){search_ajax_call(),$("#searchbar-input").val().length>0&&$("#search-dropdown").html().length>0&&$("#search-dropdown").show(0,set_first_result_focused)}),$("#search-dropdown").bind("DOMSubtreeModified",function(){$(this).html().length===0?$(this).hide():set_first_result_focused()});