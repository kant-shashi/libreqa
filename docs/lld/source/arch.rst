Architecture
************
It is assumed that standard MongoDB sharding will be used as shown (the
image was shamelessly copied from http://www.mongodb.org ) below:

.. image:: _static/sharding.PNG
   :align: center
   :alt: Database architecture

User can hit MongoDB's website to know about it.

Models
======

Questions & Answers
-------------------
Folowing model(read collection) is in picture for questions and answers::

	{
		Questions : {
			Question no. : Long Long,
			title 	     : String,
			Body  	  	 : html,
			tags  	  	 : Sorted List of Strings,
			view  	  	 : Integer,
			votes     	 : Integer,
			favorite  	 : Inetger,
			timestamp 	 : Timestamp,
			Followers	 : List of users,
			Comments 	 :List of comments {
				comment    : String,
				timestamp  : TimeStamp,
				commeneter : user,
			},
			answers : List of answers {
				Answer id : Long Long,
				answer    : String,
				accepted  : Boolean,
				votes	  : Integer,
				Comments  : List of comments {
					comment    : String,
					timestamp  : TimeStamp,
					commeneter : user,
				},
			},
		},
	}

Following model(read collection) is for users::

	{ 
		Users: {
			Name		  : String,
			Email id	  : String,
			URL			  : String,
			Date of Birth : Date,
			Karma		  : Long Long,
			Skills		  : Tags,
			Badges    	  : List of Badges {
				Badge Name 	  : Name,
				Date Acquired : Date,
			},
			Questions : List of Questions Asked {
				Question URL : String,
			},
			Answers : List of Answers Given {
				Question URL with answer ref: URL,
			}
		}
	}

Following collection is for tags::

	{
		Tags : {
			Name : String,
			Count : Integer,
			links : List of question for that tag {
				link: URL
			}
		}
	}

Following collection is for badges::

	{
		Badges : {
			Users : List of people having that badge,
			Count : Long Long,
		}
	}