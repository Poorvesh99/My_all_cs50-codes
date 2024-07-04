var abra = "images/abra.jpg";
var jynx = "images/jynx.jpg";
var mim = "images/mimikyu.avif";
var spirit = "images/spiritomb.jpg";
var mag = "images/magikarp.jpg";



var count = 0;
function previous()
{
    count--;

    if (count == -1){count = 4;}

    if(count == 0){document.getElementById("gimg").attributes[1].value=abra;}
    else if (count == 1){document.getElementById("gimg").attributes[1].value=jynx;}
    else if (count == 2){document.getElementById("gimg").attributes[1].value=mim;}
    else if (count == 3){document.getElementById("gimg").attributes[1].value=spirit;}
    else if (count == 4){document.getElementById("gimg").attributes[1].value=mag;}

    document.getElementById('ans').style.backgroundColor = 'white';
    document.getElementById('reply').innerHTML =' ';

}

function next()
{
    count = (++count) % 5;


    if(count == 0){document.getElementById("gimg").attributes[1].value=abra;}
    else if (count == 1){document.getElementById("gimg").attributes[1].value=jynx;}
    else if (count == 2){document.getElementById("gimg").attributes[1].value=mim;}
    else if (count == 3){document.getElementById("gimg").attributes[1].value=spirit;}
    else if (count == 4){document.getElementById("gimg").attributes[1].value=mag;}

    document.getElementById('ans').style.backgroundColor = 'white';
    document.getElementById('reply').innerHTML =' ';
}

function checkans()
{
                var ans = document.getElementById('ans').value.toLowerCase();
                if ((ans == 'abra' && count == 0) || (ans == 'jynx' && count == 1) || (ans == 'mimikyu' && count == 2) || (ans == 'spiritomb' && count == 3) || (ans == 'magikarp' && count == 4))
                {
                    document.getElementById('ans').style.backgroundColor = 'green';
                    document.getElementById('reply').innerHTML ='Correct!';
                }
                else if (ans == 'pikachu' && count == 2)
                {
                    document.getElementById('ans').style.backgroundColor = 'red';
                    document.getElementById('reply').innerHTML ='Ha! Ha! not a Pikachu';
                }
                else
                {
                    document.getElementById('ans').style.backgroundColor = 'red';
                    document.getElementById('reply').innerHTML ='Incorrect';
                }
}