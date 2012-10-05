Requirement Specification
*************************
Following are the requirenment specification of libreQA. These are organized in
different functional sections.

The entire interface must be themable using CSS.

Login
=====
Following requirements are mandatory:

1. User must be able to login with Google or Facebook.
2. User must be able to create a login with a password.
3. Password should be strong. This check must be performed for at least 8
   character, 3 character class password. A captcha test is needed to prevent
   bot registration.
4. User needs to give a working email at registration time. This email-id must
   get a validdation email.
5. Upon validation the account must be activated else the user is not allowed
   to use the website.
6. In case user forgets his password a link must be provided to reset his password
   by providing a password reset link by email to his email-id.
7. On clicking Logout button user must be logged out.

Q&A
===
It is assumed that users are logged in while modifying content.
Following requirements are mandatory:

1. User should be able to ask a question. Title must be 10 charcaters long or
   as configfured.
2. Question should be at least 3 words or as configured.
3. At least one tag should be used. It may exist or created if it does not.
4. TinMCE should be used with https://github.com/RichGuk/syntaxhl ,
   https://github.com/efloti/plugin-mathjax-pour-tinymce and optionally
   http://web.chemdoodle.com/ should be integrated.
5. At least 10 words or as configured for answers.
6. Maximum 1000 words for questions and answers or as confiured.
7. Maximum 600 words for comments. This will be plain text.
8. Questions and answers can be voted up and down.
9. Questions can be marked favorite.
10. Answers can be accepted. Only the OP should be able to accept the answer.
11. Reputation gain is entirely configurable and is covered separately.
12. Questions, answers and comments can be edited and deleted.
13. Upon deletion they will not be shown and marked for deletion.
14. Questions can be closed by admins.
15. Questions can be made sticky and un-sticky.
16. Questions can be retagged.
17. Questions can be reported to admins as inappropriate.
18. Similar questions should be shown on question page.
Following requirements are mandatory:

1. User should be able to ask a question. Title must be 10 charcaters long or
   as configfured.
2. Question should be at least 3 words or as configured.
3. At least one tag should be used. It may exist or created if it does not.
4. TinMCE should be used with https://github.com/RichGuk/syntaxhl ,
   https://github.com/efloti/plugin-mathjax-pour-tinymce and optionally
   http://web.chemdoodle.com/ should be integrated.
5. At least 10 words or as configured for answers.
6. Maximum 1000 words for questions and answers or as confiured.
7. Maximum 600 words for comments. This will be plain text.
8. Questions and answers can be voted up and down.
9. Questions can be marked favorite.
10. Answers can be accepted. Only the OP should be able to accept the answer.
11. Reputation gain is entirely configurable and is covered separately.
12. Questions, answers and comments can be edited and deleted.
13. Upon deletion they will not be shown and marked for deletion.
14. Questions can be closed by admins.
15. Questions can be made sticky and un-sticky.
16. Questions can be retagged.
17. Questions can be reported to admins as inappropriate.
18. Similar questions should be shown on question page.
19. It will be a replica of http://android.stackexchange.com

Administrative Panel
====================
1. The dashboard will have a summary containing quick statistics which will
   have count of total questions/answers/users and for last 24 hours.
2. Site will have a bootstrap mode where reputation constraints are relaxed.
3. All the recent activity will be shown with 10/configurable items per page.
4. Admin menu will be a replica of OSQA.

General Interface
=================
1. It will be a replica of http://android.stackexchange.com

Badges
======
1. Combination of OSQA, stackexchange, shapado, quora and everything else.

Search
======
1. We will not provide any search facility. Google search has to be configured.
