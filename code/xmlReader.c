#include <stdio.h>
#include <libxml/parser.h>

void experiment(int count, int length, int max);

void parseNode(xmlNode *node) {
  xmlNode *curNode = NULL;
  for (curNode = node; curNode; curNode = curNode->next) {
    if (curNode->type == XML_ELEMENT_NODE) {
      if (xmlStrcmp(curNode->name, (const xmlChar *)"nodes") == 0) {
        xmlChar *countAttr = xmlGetProp(curNode, (const xmlChar *)"count");
        xmlChar *lengthAttr = xmlGetProp(curNode, (const xmlChar *)"length");
        xmlChar *maxAttr = xmlGetProp(curNode, (const xmlChar *)"max");

        if (countAttr && lengthAttr && maxAttr) {
          int count = atoi((const char *)countAttr);
          int length = atoi((const char *)lengthAttr);
          int max = atoi((const char *)maxAttr);
          
          printf("\nCount: %d, Length: %d, Max: %d", count, length, max);
          
          experiment(count, length, max);
        }

        xmlFree(countAttr);
        xmlFree(lengthAttr);
        xmlFree(maxAttr);
      }

      parseNode(curNode->children);
    }
  }
}

int xmlReader() {
  xmlDoc *doc = NULL;
  xmlNode *root = NULL;

  doc = xmlReadFile("experiment.xml", NULL, 0);
  if (doc == NULL) {
    printf("Failed to parse XML document.\n");
    return 1;
  }

  root = xmlDocGetRootElement(doc);
  if (root == NULL) {
    printf("Empty XML document.\n");
    xmlFreeDoc(doc);
    return 1;
  }

  parseNode(root);

  xmlFreeDoc(doc);
  xmlCleanupParser();
  return 0;
}
