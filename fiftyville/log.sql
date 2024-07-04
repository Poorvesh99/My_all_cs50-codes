-- Keep a log of any SQL queries you execute as you solve the mystery.
-- first table structure with
.schema
-- To check what kind of data crime_scene_reports contain I run
SELECT * FROM crime_scene_reports;
--Run the following command to check the description of duck robbery and it's location
SELECT * FROM crime_scene_reports WHERE description LIKE '%Duck%';
--Then form above we found witness metion bakery so to check there itreviews i searched
SELECT * FROM interviews WHERE transcript LIKE '%bakery%';
--to reflect on ruth interciew i first check bakery security log data fromat by
SELECT * FROM bakery_security_logs;
 -- Then check the the license plate of people left during that time by
SELECT * FROM bakery_security_logs WHERE day = 28 AND  hour = 10 AND minute > 15 AND
minute < 25 AND activity = 'exit';
-- There were multiple people so i check over eugen interview by checking the transaction at leggett street that withdraw by
SELECT * FROM atm_transactions
WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type ='withdraw';
-- Then accoriding to Raymond interview i went on to check first flight to leave fiftyville
SELECT * FROM flights
JOIN airports ON origin_airport_id = airports.id
WHERE day = 29 AND origin_airport_id = 8;
--before this command we found form flight table that fiftyville id is 8 form it first flight to leave is with id 36 and destination id is 4
-- FROM following command we found destination of theft which is
SELECT * FROM airports WHERE  id = 4;
-- from following command we find the passanger's passport no. traveling through that flight
SELECT * FROM passengers WHERE flight_id = 36;
--now we will find id of people who left bakery using there licence id
SELECT id FROM people
WHERE license_plate  IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND  hour = 10 AND minute > 15 AND
minute < 25 AND activity = 'exit');
-- from running this command we find a id belonging to people
-- now we will check the id of those who perform transactions
SELECT person_id FROM bank_accounts
WHERE account_number IN (SELECT account_number FROM atm_transactions
WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type ='withdraw');
--now we will find the passanger id traveling through the plane
SELECT id FROM people
WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);
--from following command we narrow down them to two peole

SELECT * FROM people
WHERE id IN (SELECT id FROM people
WHERE license_plate  IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND  hour = 10 AND minute > 15 AND
minute < 25 AND activity = 'exit')
INTERSECT
SELECT person_id FROM bank_accounts
WHERE account_number IN (SELECT account_number FROM atm_transactions
WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type ='withdraw')
INTERSECT
SELECT id FROM people
WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36));

---so to narrow it all down we check the who had less than 1 min iteraction at that day by
SELECT id FROM people
WHERE phone_number IN (SELECT caller FROM phone_calls
WHERE day = 28 AND month = 7 AND duration >= 60);

-- so later performoing following query we found the theif which is bruce
SELECT * FROM people
WHERE id IN (SELECT id FROM people
WHERE license_plate  IN (SELECT license_plate FROM bakery_security_logs WHERE day = 28 AND  hour = 10 AND minute > 15 AND
minute < 25 AND activity = 'exit')
INTERSECT
SELECT person_id FROM bank_accounts
WHERE account_number IN (SELECT account_number FROM atm_transactions
WHERE month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type ='withdraw')
INTERSECT
SELECT id FROM people
WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36)
INTERSECT
SELECT id FROM people
WHERE phone_number IN (SELECT caller FROM phone_calls
WHERE day = 28 AND month = 7 AND duration >= 60));
-- to check his accomplice first we check to what no. he called
SELECT receiver FROM phone_calls
WHERE caller = '(367) 555-5533' AND day = 28 AND month = 7 AND duration <= 60;

-- then we found bruce accomplish is robin by following query
SELECT name FROM people
WHERE phone_number = (SELECT receiver FROM phone_calls
WHERE caller = '(367) 555-5533' AND day = 28 AND month = 7 AND duration <= 60);

-- THE END --





