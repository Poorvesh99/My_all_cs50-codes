# Scorio
#### Video Demo:  <https://youtu.be/r8KjWXprL0Y>
#### Description:
##### Introduction

Scorio is the web application developed in python with the help of flask library. The front end is developed through HTML and CSS. This web application let you know the live score of the matches that are being currently played around the word. It provides the user with score as a small scorecard similar to one which are presented by the google. These Scorecard is available for five major sports which are Football, Cricket, Basketball, Hockey, Tennis. On top of this application let you know the Scorecard for the matches which are already been conducted on any particular date. It also provides with fixtures scheduled to be happened and which are known officially to public.

##### API

To implement the feature of showing live score I make use of the API LiveScore by Api Dojo from https://rapidapi.com/. This API let the user query for match details from the above-mentioned sports. It provides the user this data in the format of JSON file. This API take sport name as query and provide all the current details about the games as a long JSON file which have all the information about the game at that moment.

##### Layout
My web application begins with one page written in HTML page with name layout.html carrying out the layout of the web application. It contains navbar on top which contains the 5-buttons aligned to centre for every sport. To implement It I use flex-box div to incorporate the items that may follow in the navbar as I keep the room for improvement in the design. Following this layout, I create five webpages with their own individual designs. Each one of these pages come with an element similar to navbar which let you know whether you are seeing the result belong to live matches or the matches from any particular day, with the help of button holding name “live” if page is displaying current matches otherwise Date of matches you are viewing. If you click on this button, expanded “HTML form” appear right below the button which contain one input field of type ‘date’ and button named ‘search’, I incorporate this feature with the use of bootstrap. In input you select the date from which you want to view matches. If date is in past the resultant page will show the matches that are held on that date with their score and if the date is for any recent future, The page will contain the fixtures that are scheduled for that day. If none It will also let you know about it. Otherwise on default the webpage will show the scorecards for live matches.

##### Main page design

Following the live bar next come in web application is the match container which will hold the matches this division spread throughout the page following the live-bar. This match container is also a flex-box to incorporate any additional functionality, in the middle of this container I add another division which is made up of grid of matches scorecard, I setup this with the grid-box structure offered by CSS. Each row in the grid is scorecard. To incorporate any number of matches may come I use ‘for-loop’ in jinja.

##### Scorecard

The Scorecard for every match is primarily divided into three parts which begins with the name of league and type of match, second part consists of team’s name and score this part changes apparency according to the sport. In case of football, hockey and basket it is pretty standard in which division is divided into 3-part, first part consists of team logo with name under it and team score following it. Then there come ‘- ‘to divide the both teams, which is then later supported by second team score, logo and team name under logo exactly in that order. But in case of cricket this format slightly change as cricket can have ‘Test’ matches which needed two scores to represent the match result also the Api lacks the  team’s logos so it is  just represented with name and score, in cricket score part contain runs they scored and number of  fallen wickets of the team. In case of tennis, we begin with session following up row wise two columns where each column has the name of player and score, he/she scored in every session as there is possibilities of only up to 5 which is later followed by the current session points, which is then companied with the number of sets any particular team had won. Third part of the scorecard contain the current phase in match that is current game duration during football or hockey match, overs in cricket match, quarters or session in basketball and tennis respectively. Just below this there is status of match.

##### Design view
I have kept design fairly simple and clean to incorporate the expansion of the project. Due to college strict timeline, I had very short time to complete so I included primary function and kept the project on hold to expand. But I needed to complete the course to begin CS50 AI. This I how I am going to present the project for my CS50 final project.

