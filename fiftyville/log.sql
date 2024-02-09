-- Keep a log of any SQL queries you execute as you solve the mystery.
--Took place on 28th July and on Humphrey Street

THIEF Info


LIST OF SUSPECTS
--Whitnesses (Ruth, Eugene, Raymond)
(246 (sus), 264, 266, 267, 269 (sus), 275, 288 (sus), 313, 336 (sus))
(246, 269, 288, 336) -- all left the bakery in the time frame AND withdrew from the atm on legett st

 Bruce, Luca, Iman, Diana (--match with atm and leaving bakery)

It was Dianna


--SQL queries

-- Start point analyze information
SELECT * FROM crime_scene_reports
WHERE month = 7 AND day = 28
--Report time of theft 10:15am at the Humphrey Street bakery, three witnesses were present/ interviews

SELECT transcript FROM interviews
WHERE month = 7 AND day = 28
AND interviews.transcript LIKE '%bakery%';
--Ruth("...within 10 minutes the thief got into car and drove away...")
--Eugene("Someone I recognised...Thief withdrew money that mourning from ATM on Leggett Street.. earlier that day ")
--Raymond("As thief was leaving they called someone for less than a minute... in the call i heard them say they will take earliest flight out of fiftyville tomorrow. The thief then asked the other person on the line to purchas the flight ticket")

SELECT * FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <= 25);
-- chekcing security footage of bakery for liscence plate
-- Between times 10:15~10:25am we have 8 plates + 1 at 10:35am exit
-- id number: 260~268

-- look up plates in people table

SELECT * FROM people
INNER JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND (minute >= 15 AND minute <= 25);
-- 8 people from liscence cross refrence Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey

-- follow up and check atm records, check for account number and cross refrence with bank_accounts.person_id that with 8 suspects from cctv footage

SELECT people.name, atm_transactions.transaction_type FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2021
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_location = 'Leggett Street'
AND atm_transactions.transaction_type = 'withdraw';


SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
WHERE people.id IN (246, 264, 266, 267, 269, 275, 288, 313, 336)
ORDER BY account_number;

SELECT id
FROM people
WHERE id IN (246, 264, 266, 267, 269, 275, 288, 313, 336);

SELECT * FROM bank_accounts
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE bank_accounts.account_number IN (28500762, 28296815, 76054385, 49610011, 16153065, 86363979, 25506511, 81061156, 26013199)
ORDER BY account_number;

-- now check for also people id
SELECT * FROM bank_accounts
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE bank_accounts.account_number IN (28500762, 28296815, 76054385, 49610011, 16153065, 86363979, 25506511, 81061156, 26013199)
AND bank_accounts.person_id IN (246, 264, 266, 267, 269, 275, 288, 313, 336)
ORDER BY account_number;

-- im stupid and have to manually check just ignore



--check third witness with flight


SELECT name FROM people
JOIN flights ON flights.id = people.id
JOIN airports ON airports.id = people.id
WHERE airports.city = 'Fiftyville'
AND flights.year = 2021
AND flights.month = 7
AND flights.day = 29
AND name IN ("Bruce", "Diana", "Iman", "Luca");

--WHERE origin_airport_id = (SELECT airports.id FROM airports WHERE city = 'Fiftyville')