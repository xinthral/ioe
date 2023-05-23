import '../../index.css';
import {createBrowserRouter} from 'react-router-dom';
import Root, { 
  loader as rootLoader,
  action as rootAction,
} from '../root';
import ErrorPage from '../r_errors/error-page';
import Contact, {
  loader as contactLoader,
} from '../r_contacts/contacts';
import EditContact, {
  action as editAction,
} from '../r_contacts/edit';
import { action as destroyAction } from '../r_contacts/destroy';
import Index from '../index';

const router = createBrowserRouter([
  {
    path: "/",
    element: <Root />,
    errorElement: <ErrorPage />,
    loader: rootLoader,
    action: rootAction,
    children: [
      { 
        index: true, 
        element: <Index />,
      },
      {
        path: "/contacts/:contactId",
        element: <Contact />,
        errorElement: <ErrorPage />,
        loader: contactLoader,
      },
      {
        path: "contacts/:contactId/edit",
        element: <EditContact />,
        loader: contactLoader,
        action: editAction,
      },
      {
        path: "contacts/:contactId/destroy",
        action: destroyAction,
        errorElement: <div>Error! We Computered too hard and had an oopsie.</div>,
      },
    ],
  },
  {
    path: "/test",
    element: <div>Hello world!</div>,
  },
]);

export default router;