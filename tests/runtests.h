//
// Created by Adam Hedges on 6/17/21.
//

#ifndef JSONPARSER_RUNTESTS_H
#define JSONPARSER_RUNTESTS_H

const int TEST_LABEL_PREFIX_LEN = 30;

int testTokenStream();

int testArrayParser();
int testObjectParser();

int testJsonArray();
int testJsonBoolean();
int testJsonFloat();
int testJsonInteger();
int testJsonNull();
int testJsonObject();
int testJsonString();

#endif //JSONPARSER_RUNTESTS_H
