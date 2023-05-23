import { redirect } from 'react-router-dom';
import { deleteContact } from './f_contacts';

export async function action({ params }) {
    // throw new Error("Oh Snappers!");
    await deleteContact(params.contactId);
    return redirect('/');
}