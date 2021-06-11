typedef struct TSinglLinkElement {
	void *data;
	struct TSinglLinkElement *next;
} TSinglLinkElement;

typedef short int TCheckFunc(void *D1, void *D2);

TSinglLinkElement* GetPrevSinglLinkElement(TSinglLinkElement* First, TSinglLinkElement* CurrentElement) {
	while (First != NULL)
	{
		if ((*First).next == CurrentElement)
		{
			return First;
		}
		First = (*First).next;
	}
	return NULL;
}

TSinglLinkElement* InsertSinglLinkElement(TSinglLinkElement* CurrentElement, void* D) {
	TSinglLinkElement* E;
	E = (TSinglLinkElement*)malloc(sizeof(TSinglLinkElement));
	(*E).data = D;
	if (CurrentElement == NULL) {
		(*E).next = NULL;
	}
	else
	{
		(*E).next = (*CurrentElement).next;
		(*CurrentElement).next = E;
	}
	return E;
}

void DeleteNextSinglLinkElement(TSinglLinkElement* CurrentElement) {
	TSinglLinkElement* Next;
	Next = (*CurrentElement).next;
	if (Next == NULL) { return; }

	(*CurrentElement).next = (*Next).next;

	free((*Next).data);
	free(Next);
}

TSinglLinkElement* SearchSinglLinkElementData(TSinglLinkElement* CurrentElement, void *Val, TCheckFunc f) {
	while (CurrentElement != NULL)
	{
		if (f((*CurrentElement).data, Val) == 0)
		{
			return CurrentElement;
		}
		CurrentElement = (*CurrentElement).next;
	}
	return NULL;
}