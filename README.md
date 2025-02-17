## FakeRest 

C++ simple Rest Client which queries "http://test.brightsign.io:3000" and process the response.  The following data
is calculated and output in a json structure:
-  AverageAge - average age of users in each city
-  AverageFriends - average numer of friends in each city
-  MostFriends - user name with the most friends in each city
-  MostCommonHobby - most common hobby over all users in all cities
-  MostCommonFirstName - most common user name over all users in all cities

NOTE:  HTTP is insecure as the data is transmitted in plain text.  
Security could be added to the server using https:// instead of http:// for REST API URLs. Then ensuring the server
is configured with a valid SSL/TLS certificate.

Other methods includ Authentication such as API keys, and third party tokens.  API keys are a simple way to authenticate API requests. Ensure keys are stored securely and rotated periodically. Another method is to authenticate via third-party service such as Google and provides tokens for authorization.


## Prerequiste

Install nlohmann-json3-dev Using apt-get

sudo apt update
sudo apt-get -y install nlohmann-json3-dev

## Building 

git clone https://github.com/swhitake-g/FakeRest.git

cd Assignment
make

## Running

./FakeRest "http://test.brightsign.io:3000" 

## Example Output

{
  "Cities": {
    "Austin": {
      "AverageAge": "58.543121",
      "AverageFriends": "4.016656",
      "MostFriends": "Emily"
    },
    "Boston": {
      "AverageAge": "58.704739",
      "AverageFriends": "3.983877",
      "MostFriends": "Michael"
    },
    "Branson": {
      "AverageAge": "58.119701",
      "AverageFriends": "3.993392",
      "MostFriends": "Oliver"
    },
    "Charleston": {
      "AverageAge": "57.940681",
      "AverageFriends": "3.990196",
      "MostFriends": "Amelia"
    },
    "Chicago": {
      "AverageAge": "58.335655",
      "AverageFriends": "3.987932",
      "MostFriends": "Grace"
    },
    "Honolulu": {
      "AverageAge": "58.933182",
      "AverageFriends": "3.990115",
      "MostFriends": "Luke"
    },
    "Lahaina": {
      "AverageAge": "58.940487",
      "AverageFriends": "3.999119",
      "MostFriends": "Camila"
    },
    "Las Vegas": {
      "AverageAge": "58.340118",
      "AverageFriends": "3.972271",
      "MostFriends": "Isabella"
    },
    "Los Angeles": {
      "AverageAge": "58.144325",
      "AverageFriends": "4.012539",
      "MostFriends": "Noah"
    },
    "Miami Beach": {
      "AverageAge": "59.114796",
      "AverageFriends": "4.002041",
      "MostFriends": "Emma"
    },
    "Nashville": {
      "AverageAge": "58.348984",
      "AverageFriends": "3.962591",
      "MostFriends": "Charlotte"
    },
    "New Orleans": {
      "AverageAge": "58.658146",
      "AverageFriends": "4.008104",
      "MostFriends": "Noah"
    },
    "New York City": {
      "AverageAge": "58.661674",
      "AverageFriends": "3.984775",
      "MostFriends": "Charlotte"
    },
    "Orlando": {
      "AverageAge": "58.276379",
      "AverageFriends": "3.999499",
      "MostFriends": "Isabella"
    },
    "Palm Springs": {
      "AverageAge": "58.188957",
      "AverageFriends": "3.987287",
      "MostFriends": "Liam"
    },
    "Portland": {
      "AverageAge": "58.461025",
      "AverageFriends": "4.023636",
      "MostFriends": "Daniel"
    },
    "Saint Augustine": {
      "AverageAge": "58.455776",
      "AverageFriends": "4.001491",
      "MostFriends": "Elijah"
    },
    "San Antonio": {
      "AverageAge": "58.610180",
      "AverageFriends": "4.012567",
      "MostFriends": "Chris"
    },
    "San Diego": {
      "AverageAge": "58.212761",
      "AverageFriends": "3.994381",
      "MostFriends": "Robert"
    },
    "San Francisco": {
      "AverageAge": "58.567162",
      "AverageFriends": "3.983348",
      "MostFriends": "Elijah"
    },
    "Savannah": {
      "AverageAge": "58.311043",
      "AverageFriends": "3.976835",
      "MostFriends": "Lucas"
    },
    "Seattle": {
      "AverageAge": "58.569828",
      "AverageFriends": "4.019519",
      "MostFriends": "Michael"
    },
    "Sedona": {
      "AverageAge": "58.018448",
      "AverageFriends": "4.022311",
      "MostFriends": "Daniel"
    },
    "St. Louis": {
      "AverageAge": "58.427471",
      "AverageFriends": "3.978286",
      "MostFriends": "Emily"
    },
    "Washington": {
      "AverageAge": "58.715542",
      "AverageFriends": "3.992580",
      "MostFriends": "Sophie"
    }
  },
  "MostCommonInAllCities": {
    "MostCommonHobby": "Collecting",
    "MpstCommonFirstName": "Oliver"
  }
}

